#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
stack<int>s;
int n,m,a[1000005],b[1000005],c[1000005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=0;l<=n;l++){
		while(s.size()){
			s.pop();
		}
		for(int i=1;i<=m;i++){
			b[i]=0;
		}
		for(int i=l+1;i<=n;i++){
			if(b[a[i]]==0){
				s.push(a[i]);
				b[a[i]]++;
			//	c[a[i]]++;
			}
			else{
			//	c[a[i]]++;
				b[a[i]]++;
				while(s.size()){
					if(s.top()==a[i]){
						b[a[i]]--;
						s.pop();
						break;
					}
					else{
						b[s.top()]--;
						s.pop();
					}
				
				}
			
			}
		}
		for(int j=1;j<=m;j++){
		//	cout<<b[j]<<" ";
				if(b[j]>0){
					c[j]++;
				}
			}
//	cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
