/*
5 5
1 2 4 8 9

*/ 

#include<bits/stdc++.h >
using namespace std;
long long n,m;
long long a[5000009];
long long flag = 0;
long long cb = 0;
long long ccb[5009][5009];
bool sl(int l,int r) {
	long long tp = ccb[r][r]-ccb[r][l-1];
	if(tp<=m){
		return 1;
	}else{
		return 0;
	} 
//	long long tt = a[r];
//	long long ls = 0;
//	long long tmp = m;
//	for(int i = l; i<r; i++) {
//		tmp-=(a[r]-a[i]);
//		if(tmp<0) {
//			return 0;
//		}
//	}
	
}

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i<=n; i++) {
		cin>>a[i];
//		s[i] = s[i-1]+a[i];
		if(a[i]!=i) {
			flag = 1;
		}

	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=i;j++){
			ccb[i][j] = a[i]-a[j];
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=i;j++){
			ccb[i][j] = ccb[i][j-1]+ccb[i][j];
		}
	}
//	for(int i = 1;i<=n;i++){
//		for(int j = 1;j<=i;j++){
//			cout<<ccb[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cb = a[2]-a[1];
	bool fg = 0;
	for(int i = 3; i<=n; i++) {
		if(a[i]-a[i-1]!= cb) {
			fg = 1;
			break;
		}
	}
	if(!flag) {
		long long xb = n;
		long long num = 0;
		while(1) {
			m-=(n-xb);
			if(m<0) {
				break;
			}
			xb--;
			num++;
		}
		cout<<num<<endl;
		return 0;
	}
	if(!fg) {
		long long xb = n;
		long long num = 0;
		while(1) {
			m-=cb;
			if(m<0) {
				break;
			}
			xb--;
			num++;
		}
		cout<<num<<endl;
		return 0;
	}
	long long temp = -1;
	for(long long i = 1; i<=n; i++) {
		for(long long j = 1; j<=n; j++) {
			if (sl(i,j)) {
				temp = max(temp,(j-i+1));
			}
		}
	}
//	cout<<sl(1,3);
	cout<< temp;
	return 0;
}

// 5 5
//1 2 4 8 9
//0 1 2 4 1
//1 3 7 15 24

//1 3 5 7 9 11 13 15 17
//1 2 3 4 5 6 7 8
//#include<bits/stdc++.h >
//using namespace std;
//long long n,m;
//long long a[5000009];
//long long s[5000009];
//long long flag = 0;
//long long cb = 0;
//bool sl(int l,int r) {
//	long long tt = a[r];
//	long long ls = 0;
//	long long tmp = m;
//	for(int i = l; i<r; i++) {
//		tmp-=(a[r]-a[i]);
//		if(tmp<0) {
//			return 0;
//		}
//	}
//	return 1;
//}
//int main() {
////	freopen("r","crystal.in",stdin);
////	freopen("w","crystal.out",stdout);
//	cin>>n>>m;
//	s[0] = 0;
//	for(int i = 1; i<=n; i++) {
//		cin>>a[i];
//		s[i] = s[i-1]+a[i];
//		if(a[i]!=i) {
//			flag = 1;
//		}
//	}
//	sort(a+1,a+n+1);
////	cout<<sl(1,3);
//	cb = a[2]-a[1];
//	bool fg = 0;
//	for(int i = 3; i<=n; i++) {
//		if(a[i]-a[i-1]!= cb) {
//			fg = 1;
//			break;
//		}
//	}
//	if(!flag) {
//		long long xb = n;
//		long long num = 0;
//		while(1) {
//			m-=(n-xb);
//			if(m<0) {
//				break;
//			}
//			xb--;
//			num++;
//		}
//		cout<<num<<endl;
//		return 0;
//	}
//	if(!fg) {
//		long long xb = n;
//		long long num = 0;
//		while(1) {
//			m-=cb;
//			if(m<0) {
//				break;
//			}
//			xb--;
//			num++;
//		}
//		cout<<num<<endl;
//		return 0;
//	}
//	long long temp = -1;
//	for(long long i = 1; i<=n; i++) {
//		for(long long j = 1; j<=n; j++) {
//			if (sl(i,j)) {
//				temp = max(temp,(j-i+1));
//			}
//		}
//	}
////	cout<<sl(1,3);
//	cout<< temp;
//	return 0;
//}
//
//// 5 5
////1 2 4 8 9
////0 1 2 4 1
////1 3 7 15 24
//
////1 3 5 7 9 11 13 15 17
////1 2 3 4 5 6 7 8
