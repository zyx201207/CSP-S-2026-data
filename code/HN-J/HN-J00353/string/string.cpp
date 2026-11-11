#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000001],l,r,s1,s2,s3;
char b[1000001];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	l=1,r=n,s1=a[1],s2=a[n];
	while(l<r){
//		cout<<s1<<" "<<s2<<" "<<s3<<" "<<l<<"\n";
		if(s1>s2){
			if(b[l]!=b[r]) s3+=s2;
			r--;
			s1-=s2;
			s2=a[r];
		}
		else if(s1<s2){
			if(b[l]!=b[r]) s3+=s1;
			l++;
			s2-=s1;
			s1=a[l];
		}
		else {
			if(b[l]!=b[r]) s3+=s1;
			l++,r--;
			s1=a[l],s2=a[r];
		}
	}
	cout<<s3;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
