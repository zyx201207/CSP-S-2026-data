//就是这样,Sadbee_qwq。
#include <iostream>
#include <algorithm>
#define mian main
#define maxn 2000006
#define inf 2147483647
#define mid ((l+r)/2)
/*>-<*/
using namespace std;

long long yeah_i_will_change_all_this_varieble_into_this[maxn],d[maxn];
//long long tst[maxn];

/*
int129.ppt
ac 不 了 那场比赛？
事实：
比赛很难
而你是蒟蒻
而且CCF只顾着飞。
（它最坏了)

不可能的任务？
（小人挠头.png）
 
介绍::int129!
*/

void get(__int128 &a) {
	long long tmp;
	cin>>tmp;
	a=tmp;
}

void print(__int128 a) {
	if(a<0) {
		putchar('-');
		a=-a;
	}
	if(a>9) {
		print(a/10);
	}
	putchar(a%10+'0');
}

//二分？
//im so vegetaqle.
int n,m;
long long l,r;

long long rsum(int l,int r) {
	return yeah_i_will_change_all_this_varieble_into_this[r]-yeah_i_will_change_all_this_varieble_into_this[l];
}

bool testt(int c,int m) {
	/*
	A is for Apple
	B is for Banana
	C is for CCF
	*what is ccf?
	*it's an acronym.
	*it means for Chinese Can Fly
	中国人会飞~中国人会飞~中国人会飞~
	*/
//	cout<<"testing for count:"<<c<<'\n';
	int tst=0;
	int l=n-1,r=n-1;
	while(r-l<c) {
		tst+=rsum(l,r);
//		cout<<tst<<'\n';
		l--;
	}
	while(l>=0) {
		if(tst<=m) {
			return 1;
		}
		tst+=rsum(l,r);
//		cout<<tst<<'\n';
		l--;//debug is sooooooo painful 喵喵喵
		tst-=d[r]*c;
		r--;
//		cout<<tst<<'\n';
	}
	if(tst<=m) {
		return 1;
	}
	return 0;
}

int mian() {
	//Do you know that niko is cute?
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	//niko who?
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>yeah_i_will_change_all_this_varieble_into_this[i];
	}
	//我们需要扫地机器人骑乘赛车比赛OwO
	sort(yeah_i_will_change_all_this_varieble_into_this,yeah_i_will_change_all_this_varieble_into_this+n);
	for(int i=1; i<n; i++) {
		d[i]=yeah_i_will_change_all_this_varieble_into_this[i]-yeah_i_will_change_all_this_varieble_into_this[i-1];
	}
	l=1,r=n;
	while(r-l>1) {
//		cout<<l<<' '<<r<<'\n';
		if(testt(mid,m)) {
			l=mid;
		} else {
			r=mid;
		}
	}
//	cout<<l<<' '<<r<<'\n';
	cout<<l;

	return 0;
}

/*
5 5
1 2 4 8 9

*/
/*
如果我打算去做点别的事情而不是在这里写些杂七杂八的东西，那么上面的话可能会很有用。
*/
/*
战术是猛吃好吃的馋死所有对手。
yummyyummy
巧克力好吃 巧克力好吃 巧克力好吃 巧克力好吃 巧克力好吃 巧克力好吃 巧克力好吃 巧克力好吃 巧克力好吃 巧克力好吃 巧克力好吃
三百颗巧克力够吗(?)
*/
