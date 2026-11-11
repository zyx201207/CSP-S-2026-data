#include<bits/stdc++.h>
using namespace std;
long long read() {
	long long x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0') {
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
struct N {
	long long x;
	string y;
} a[200010];
long long n,m,sum,zzz;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1; i<=n; i++) {
		a[i].x=read();
		cin>>a[i].y;
		m+=a[i].x;
	}
//	cout<<m<<endl;
	long long i=0,j=0,xy=0,idi=1,idj=n;
	for(; i<=m/2; i+=a[idi].x,idi++) { //i往后移
		long long w=min(i+a[idi].x,m/2);//不能超过
		while(j<w) { //不能超过
			long long wy=min(j+a[idj].x-zzz,m/2);//不能超过，原j的最大位
//			cout<<i<<" "<<j<<" "<<w<<" "<<wy<<" =-= "<<idi<<" "<<idj<<" "<<a[idi].y<<" "<<a[idi].x<<" "<<a[idj].y<<" "<<a[idj].x<<" "<<sum<<" "<<xy<<" "<<zzz<<endl;
			if(wy<=w) { //不能超过，相等则一次
				if(a[idj].y!=a[idi].y)sum+=a[idj].x-zzz;//不同则加，xy已用
				j=wy;//回原位
				xy=zzz=0,idj--;//计数器清零，j往前移
//				cout<<a[idj].x<<" "<<wy<<" "<<xy<<" "<<sum<<"-*-\n";
			} else {
				if(a[idj].y!=a[idi].y)xy+=w-j,sum+=w-j;//不同则加差
				zzz+=w-j,j=w;//开始计数，j变x
//				cout<<w<<" "<<sum<<" "<<xy<<"*-*\n";
			}
		}
	}
//	cout<<m/2<<endl;
//	long long w=min(i+a[idi].x,m/2);//不能超过
//	while(j<w) { //不能超过
//		long long wy=min(j+a[idj].x-zzz,m/2);//不能超过，原j的最大位
//			cout<<i<<" "<<j<<" "<<w<<" "<<wy<<" =-= "<<idi<<" "<<idj<<" "<<a[idi].y<<" "<<a[idi].x<<" "<<a[idj].y<<" "<<a[idj].x<<" "<<sum<<" "<<xy<<" "<<zzz<<endl;
//		if(wy<=w) { //不能超过，相等则一次
//			if(a[idj].y!=a[idi].y)sum+=wy-j-xy;//不同则加，xy已用
//			j=wy;//回原位
//			xy=zzz=0,idj--;//计数器清零，j往前移
//				cout<<a[idj].x<<" "<<wy<<" "<<xy<<" "<<sum<<"-*-\n";
//		} else {
//			if(a[idj].y!=a[idi].y)xy+=w-j,sum+=w-j;//不同则加差
//			zzz+=w-j,j=w;//开始计数，j变x
//				cout<<w<<" "<<sum<<" "<<xy<<"*-*\n";
//		}
//	}
	cout<<sum;
	return 0;
}
/*
4
29 l
66 p
34 g
58 x
*//*
8
9 b
3 b
1 b
7 a
5 c
7 b
8 b
4 b
*//*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*//*
7
18 q
37 n
94 d
19 y
97 g
93 w
33 z
*/
