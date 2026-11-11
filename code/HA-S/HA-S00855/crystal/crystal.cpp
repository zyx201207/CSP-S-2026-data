#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

int s[500001];

int cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int m_=m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+1+n,cmp);
	int max_=0;
	for(int i=1;i<=n;i++){
		m_=m;
		int j=0;
		for(j=1;j+i<=n&&m_>=0;j++){
			m_=m_-(s[i]-s[i+j]);
		}
		if(m_<0){
			j--;
		}
		max_=max(max_,j);
	}
	cout<<max_;
	return 0;
}
