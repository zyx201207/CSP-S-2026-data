#include<bits/stdc++.h>
using namespace std;
#define int long long
// <thinking>
// 水晶数量5e5
// 操作数1e18
// 必须long long才存的下
// 每个数1e12 不可以暴力乘法了 
// 等差数列?这个性质有什么用呢
// 反正看起来像一个贪心，应该不至于是dp吧
// 还有正负的
// 得仔细考虑溢出问题了 
// 样例只覆盖到10-12的点，大数据可能会设陷阱
// 注意到只能修改指定数据以下的部分
// 总而言之，我们可能需要先sort一下 
// 以及这玩意的数据量特别大 1e12 * 5e5 = 5e17
// 似乎long long还是放得下的
// 那求和操作就可以用 
// 需要找到一个数据结构，读取指定范围内所有的数与最高的数之差
// 比如1 2 4 8 9 
//   (indent)
// 找到1的时候，差是0
// 找到2的时候，1+2 = 3, 2*2 = 4, delta=1
// 找到3的时候，1+2+4 = 7, 3*4=12, delta=5 此时为最优解
// 找到4的时候，1+2+4+8=15, 5*8=40, delta>5，开始回退前指针
// 以此类推，如果delta尚有盈余的话就扩大右指针，否则缩小左指针
// 然后 我们可以用前缀和数组维护一下和
// ans负责记录两个指针之间元素个数的最大值 
// long long 19位，这里最多5e17位，应该不会爆 
// 再来个例子 
// -3 -1 2 2 7
// 1: delta=0
// 2: -4 -2 delta=2
// 3: -2 2 delta=4
// 4: 0 8 delta = 8
// 大样例坏掉了.... 
//  (t-a_1) + (t-a_2) + ... (t-a_n)
// =n*t - a_1 - a_2 ...
// =n*t - (a_1+a_2) 
// 16:06 end
// <thinking/>
const int N=1e6+9;
int n,m;
int a[N],sum[N]; 
int ans; 
int left_point;
int right_point; 
// 注意：这个函数有副作用，会顺便更新ans 
bool check(){
	int seg_sum = sum[right_point] - sum[left_point - 1];
	int required_value = 
	  a[right_point] * (right_point - left_point + 1);
	// 因已排序，所以可以知道required_value >= seg_sum
	int delta = required_value - seg_sum;
	
	// OK 现在要补的范围是够的 
//	cout<<"delta: "<<delta<<" ";
//	cout<<"m:"<<m<<" ";
//	cout<<"p_ans: "<< right_point - left_point + 1<<" ";

//	if(right_point - left_point + 1 == 380120 && delta<=m) {
//	
//	}
//	int tot = 0;
//	int delta_tot = 0;
//	int max_val = a[right_point]; 
//	for(int i=left_point;i<=right_point;i++){	
//	
//		tot+=a[i];
//		delta_tot += max_val - a[i];
//	}
//	if(tot != seg_sum){
//		// 现在的问题：tot和sum不等 
//		cout<<"tot:"<<tot<<" delta_tot:"<<delta_tot;
//		cout<<" seg_sum:"<<seg_sum<<" required_value:"<<required_value;
//		cout<<" delta:"<< delta;	
//		cout<<endl;
//		cout<<"left: "<<left_point<<" right: "<<right_point<<endl;
//		cout<<sum[0]<<endl;;
//		for(int i=left_point;i<=right_point;i++){	
//		cout<<a[i]<<" "; 
//		}
//		exit(0); 
//	}


	if(delta <= m){
		ans = max(ans, right_point - left_point + 1);
		return true;
	} 
	else{
		return false;
	} 
} 
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	// 一定要记得取消注释!!!!! 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);


	// debug only freopen!!!!! 
//	freopen("crystal2.in","r",stdin); 
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	 
	}
	sort(a+1,a+n+1);
//	死因：在排序之前求前缀和，前两个样例就是有序的所以看不出来 
	for(int i=1;i<=n;i++){
		sum[i] = a[i] + sum[i-1]; 
	}
//	for(int i=1;i<=n;i++){
//		cout<<sum[i]<<" ";
//	}
	// Warning: 注意m=0的时候的特判 
	// 现在的算法似乎没有必要特判，他自己就可以处理m=0的情况 
//	if(m==0){
//		cout<<1;
//		return 0;
//	}
 
	
	left_point = 1;
	right_point = 1;
	while(1){
		while(1){
			check();
			if(right_point == n){
				break;
			}
			if(!check()){
				break;
			}
			right_point++;
		}
		while(1){
			check();
			if(left_point == n || left_point == right_point){
				break;
			}
			if(check()){
				break;
			} 
			left_point++;
		}
		check();
		// 此时right和left已经尽可能扩展了
		// 下一轮的时候会直接被right_point==n break掉
		// 因为right_point状态没有改变，所以left也不会有改变
		// 因此，达到最终状态，break! 
		if(right_point == n){
			break;
		}  
	} 
	cout<<ans; 
	
	return 0;
} 
