#include<bits/stdc++.h>
using namespace std;
int t[50];
int p[50];
bool check_hv(string x){
    string q;
    for(int i=0;i<x.size();i++){
		q=x[i]+q;
	}
	if(q==x){
		return 1;
	}
	return 0;
}
int n,a[200005];
char r[200005];
int maxn=-0x3f3f3f3f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		string s;
		cin>>a[1]>>r[1]>>a[2]>>r[2];
		for(int i=1;i<=a[1];i++){
			s+=r[1];
		}
		for(int i=1;i<=a[2];i++){
			s+=r[2];
		}
		if(check_hv(s)==1){
			cout<<0;
		}else{
			cout<<min(a[1],a[2]);
		}
		return 0;
	}
	int sum=0;
	int last=0;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>r[i];
		int y=r[i]-'a';
		t[y]+=a[i];
		maxn=max(maxn,a[i]);
		sum+=a[i];
		last=a[i];
	}
	int man=-0x3f3f3f3f;
	if(maxn==1){
		for(int i=0;i<27;i++){
			man=max(t[i],man);
		}
		cout<<sum-man;
		return 0;
	}
	string u;
	long long ujk=0;
	for(int i=1;i<=n;i++){
		ujk+=a[i];
		p[r[i]-'a']+=a[i];
	}
	int mknj=-0x3f3f3f3f;
	for(int i=0;i<=27;i++){
		mknj=max(p[i],mknj);
	}
	cout<<ujk-mknj;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
2 a aabbc             aaavvva
	12240			  1230000
2 b
1 c

1 6
2 1 a  aaabbb
	   bbbaaa
3 1 a
4 1 a
5 1 b
6 1 b
7 1 b

2
1 a abb
2 b

1 6
2 1000000000 a 
3 1000000000 a
4 1000000000 a
5 1000000000 b
6 1000000000 b
7 1000000000 b
*/
