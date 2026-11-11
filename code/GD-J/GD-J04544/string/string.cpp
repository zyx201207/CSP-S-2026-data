#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
long long n,x,sum=0,t=0,s;
pair<string,long long>p[N];
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>a;
		if(p[t].first==a){
			p[t].second+=x;
		}
		else {
			p[++t].first=a;
			p[t].second+=x;
		}
	}
	if(t==2){
		if(p[1].second>p[2].second){
			cout<<p[2].second;
			return 0;
		}
		else {
			cout<<p[1].second;
			return 0;
		}
	}
	for(int i=1;i<=t;i++){
		if(s>0){
			if(p[i-1].first==p[t-i+2].first)s=0;
			else if(p[i-1].first!=p[t-i+2].first){
				sum+=s;
				s=0;
			}
		}
		else if(p[i].first!=p[t-i+1].first){
			if(p[i].second>p[t-i+1].second)sum+=p[t-i+1].second;
			s=p[i].second-p[t-i+1].second;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
