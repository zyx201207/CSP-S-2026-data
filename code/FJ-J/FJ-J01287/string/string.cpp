#include<bits/stdc++.h>
#define mp make_pair
using namespace std;

vector<pair<long long,char>> dq;
long long n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		long long a;
		char ch;
		cin>>a>>ch;
		dq.push_back(mp(a,ch));
	}
	long long i=0,j=n-1;
	while(i<=j){
		long long x1=dq[i].first,x2=dq[j].first;
		char y1=dq[i].second,y2=dq[j].second;
		if(y1==y2){
			i++;
			j--;
		}
		else{
			if(x1==x2){
				ans+=x1;
				i++;
				j--;
			}
			else if(x1>x2){
				ans+=x2;
				dq[i].first=x1-x2;
				dq[i].second=y1;
				j--;
			}
			else{
				ans+=x1;
				dq[j].first=x2-x1;
				dq[j].second=y2;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
