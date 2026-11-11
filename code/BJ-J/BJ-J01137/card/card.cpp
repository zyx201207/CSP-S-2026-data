#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,m,a[1000001],tong[1000001],tong1[1000001];
bool check(vector<int>x,int p)
{
	for(int i=1;i<=x.sizeof();i++){
		if(x[i]==p)return 0;
	}
	return 1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
		cin>>a[i];
		tong1[a[i]]++;
    }
    for(int i=1;i<=n;i++){
		vector<int>t;
		for(int j=i;j<=n;j++){
			if(check(t,a[j])){
				t.push_back(a[i]);
			}
			else{
				for(int u=1;u<=t.sizeof();u++){
					if(a[j]==t[u])t[u]=0;
				}
				t.push_back(a[i]);
			}
		}
		for(int j=1;j<=t.sizeof();j++){
			tong[t[j]]++;
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=a[n];i++){
		if(tong1[i])cout<<tong[a[i]];
	}
    return 0;
}
