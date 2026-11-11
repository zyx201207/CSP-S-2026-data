#include<bits/stdc++.h>

typedef long long ll;
inline ll read(){
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = - 1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f; 
}
inline void write(ll x){
	if(x < 0){
		putchar('-');
		x = - x;
	}
	if(x > 9){
		write(x / 10);
	}
	putchar(x % 10 + '0');
}
//注意不开捆绑 ,开long long  
const int MM = 5e5 + 1000;
ll b[MM];
struct node{
	ll w;
	int c;
}a[MM];
int ji[MM]; 
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n = read();
	ll m = read();
	for(int i = 1; i <= n; i++){
		b[i] = read();
	} 
	std :: sort(b + 1, b + 1 + n);
	int ans = 0, cnt = 0;
	for(int i = 1; i <= n; i++){
		if(i == 1){
			a[++cnt] = (node){b[1], 1};
		}else if(b[i] == b[i - 1]){
			a[cnt].c++;
		}else{
			a[++cnt] = (node){b[i], 1};
		}
	}
	for(int i = 1; i <= cnt; i++){
		ji[i] = a[i].c;//ji表示还剩多少个没有，额，在对列中 
	}
	n = cnt;
	int k = a[n].c, wh = 0;
	ll x = a[n].w;
	for(int i = n - 1; i >= 1; i--){
		if(m > 1ll * (x - a[i].w) * a[i].c){
			m -= 1ll * (x - a[i].w) * a[i].c;
			k += a[i].c;
			ji[i] = 0;//全部弄完了，直接==0 
		}else{
			int c = m / (x - a[i].w);
			m -= c * (x - a[i].w);
			k += c;
			ji[i] -= c;
			wh = i;//以这个结尾 
			break;
		}
	}
	ans = std :: max(ans, k);
//	std :: cout << ans << " " << wh << " " << m;
	//ji[i]表示还有多少个没有用 
	for(int i = n - 1; i >= 1; i--){
		k -= a[i + 1].c;//减去上一行的东东 
		m += 1ll * (a[i + 1].w - a[i].w) * k;//加上回来的贡献 
		x = a[i].w;//开始慢慢往下走
//		std :: cout << m << " " << k << " " << x << " " << i << " " << wh << '\n';
		while(wh > 0){
			if(m >= 1ll * (x - a[wh].w) * ji[wh]){
				m -= 1ll * (x - a[wh].w) * ji[wh];
				k += ji[wh];
//				std :: cout << k << " " << m << " " << wh << '\n';
				ji[wh] = 0;
			}else{
				int c = m / (x - a[wh].w);
				m -= c * (x - a[wh].w);
				k += c;
				ji[wh] -= c;
				break;
			}
			wh--;
		}
//		std :: cout << wh << " " << i << " " << k << '\n';
		ans = std :: max(ans, k); 
		if(wh == 0 && m >= 0){//已经到了最后一个了！！！ 
			break;
		}
	}
	write(ans);
	return 0;
}
/*
没事的，去年的我可以，今年的我也一定可以

没有什么大不了

14:30，欧克，开始考试！

注意是1024MiB，我开的是256MiB
T1: 
题目大意 ，给定一个数组，你最多可以让这一堆的数增加某一个值
求问，最多能让多少个数到达同一个水平

只能加，不能减，所以其实，稍稍大点的书，我们是放弃了的

发现，要是对于一个点，我们最后到达的平台x是

额，二分可不可以？ 
我们去分，最后到达的平台是哪个， 然后我们开始加的时候，肯定是先加在这个平台内的

不对，复杂度nlogm

那么，我们可不可以就是，额，有没有什么技术办法（哈哈，我不行了）

我真的觉得就是二分。

我们对于一个x，我们肯定只能找到就是，

但是，怎么判断，判断条件是？

（吓哭了。。。。。）

嗯，要是m还有剩余的，那么我们就稍稍的吧x放大点 

不对，额，就是这个没有单调性。。。。

我有一种很怪的感觉，就是，其实就是会一某一个点作为平台

我来验证下 

等下，相同的我们先把它放到一起 

果然，现在我已经有一个n^2得了 

（刚刚拿起1L的冰糖雪梨喝的时候旁边的哥们看了我一眼。。。。）
（对不起。。。） 

这个有单调性么？

我想想，以这个点为起点的时候，是ok的说明。在这个点附近的点有点点多

那么，我们不妨从最大的那个开始往下看，我的意思是

当我们从一个较高的点，降到稍稍低的点的时候，我们是，额，m += cha * k

k -= a[last].c

那么，我们接下来就可以用这个多的m接着去看

这个复杂度是多少?我不会算。。。。

不管了，CCF的评测机应该ok吧

嗯，还能想到别的方法么？

不能二分。。。。 

嗯，还有注意，要是从某一个点开始，就是点用完了，我们就可以直接break了 

嗯，这里不是特别好写

我的意思是，从端口这里开是

我们能不能就是再开一个数组。记录他的cnt，然后我们每次已经走了几个我们就从这个上面扣

然后，额，转移的时候怎么办？比如说，有一个点，弄半天都弄不好

然后，终于到他自己做平台了，那么这个时候，我们的w加的点就只有？只会加cha * 用了几个

旁边的哥们。。。。 

5e5的数据居然花了0.05s就跑过去了？？？？？？

6666

休息一下，回来检查！ 
*/ 
 
