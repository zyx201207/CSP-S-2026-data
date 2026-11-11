#include<bits/stdc++.h>
using namespace std;
const int N=5*100000+5;
long long n,m,a[N];
int b[N],ans[N];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<(n+1)/2;
		return 0;
	}
	if(n<=500&&m<=200){
		for(int i=0;i<n;i++){
			for(int j=1;j<=m;j++){
				b[j]=0;
			}
			while(!s.empty())s.pop();
			for(int j=i+1;j<=n;j++){
				if(b[a[j]]==1){
					int k=0;
					while(1){
						b[s.top()]--;
						int ix=s.top();
						s.pop();
						if(ix==a[j])break;
					}
				}
				s.push(a[j]);
				b[a[j]]++;
			}
		for(int j=1;j<=m;j++){
			ans[j]+=b[j];
			//cout<<b[j]<<" ";
		}
		//cout<<endl;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}
