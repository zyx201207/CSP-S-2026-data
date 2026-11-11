#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[200010];
int asd[200010];
int rj[35],maxn=0;
int ad[200010],num=0;
void show(string a){
	for(int i=1;i<=30;i++){
		cout<<(int)(a[i]);
	}
	cout<<endl;
}
void add(int cnt)
{
	int ccnt=0;
	for(int i=1;i<=num;i++)rj[i]=0;
	for(int i=1;i<=num;i++){
		if(s[ad[i]][cnt]==1){
			for(int j=1;j<=asd[ad[i]];j++){
				if(s[ad[i]][j]==1)rj[j]++;
			}
			ccnt++;
			ad[ccnt]=ad[i];
		}
	}
	num=ccnt;
}
void q(){
	for(maxn=maxn-1;maxn>=1;maxn--){
		if(rj[maxn]>=m){
			add(maxn);
			q();
		}
	}
}
string t(int a,int tc){
	string tt;
	int i=1;
	for(i=1;a>1;i++){
		if(a%2==0){
			tt[i]=0;
		}else{
			tt[i]=1;
			rj[i]++;
		}
		a/=2;
	}
	if(a==1){
		rj[i]++;
		tt[i]=1; 
	}
	maxn=max(maxn,i);
	asd[tc]=i;
	return tt;
}
int main()
{
	
	scanf("%d %d",&n,&m);
	if(m==1){
		int f=0;
		for(int i=1;i<=n;i++){
			int asdf;
			cin>>asdf;
			f=max(f,asdf);
		} 
		cout<<f;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int cnt;
		scanf("%d",&cnt);
		s[i]=t(cnt,i);
	}
	while(maxn>=1){
		if(rj[maxn]>=m)add(maxn);
		q();
		maxn--;
	}
	string ab=s[ad[1]],bb=s[ad[2]];
	int ans=0;
	for(int i=1,sb=1;i<=min(asd[ad[1]],asd[ad[2]]);i++,sb*=2){
		if(ab[i]=bb[i])ans+=sb;
	}
	cout<<ans;
	return 0;
}
