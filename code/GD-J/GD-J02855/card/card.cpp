#include<bits/stdc++.h>
#define t long long
#define ll unsigned long long
using namespace std;
t n,a[200005],m,ans,c,d[200005];
vector<t>q;
int main(int argc,char** argv)
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(t i=1;i<=n;i++){
		cin>>a[i];
		d[a[i]]++;
	}
	if(n<=500){
		for(t i=1;i<=n;i++){
			q.clear();
			for(t j=i;j<=n;j++){
				t cr=-1;
				for(t k=0;k<q.size();k++){
					if(q[k]==a[j]){
						cr=k;
						break;
					}
				}
				if(cr==-1)q.push_back(a[j]);
				else{
					while(q.size()>cr+1){
						q.pop_back();
					}
				}
			}
			for(t j=0;j<q.size();j++){
				d[q[j]]++;
			}
		}
		for(t i=1;i<=m;i++)cout<<d[i]<<" ";
		exit(0);
	}
	for(t i=1;i<=m;i++){
		cout<<(d[i]+1)/2<<" ";
	}
}
