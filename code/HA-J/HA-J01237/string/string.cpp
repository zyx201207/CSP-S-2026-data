#include <bits/stdc++.h>
using namespace std;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	vector <int> v(n);
	vector <char> vc(n);
	for(int i=0;i<n;i++){
		cin>>v[i]>>vc[i];
	}
	int k=n-1;
	for(int i=0;i<n;i++){
		if(k<=i) break;
		if(v[i]>=v[k] && vc[i]!=vc[k]){
			while(v[i]>=v[k] && vc[i]!=vc[k] && v[k]!=0){
				ans+=v[k];
				v[i]-=v[k];
				k--;
			}
		}
		if(v[i]<v[k] && vc[i]!=vc[k] && v[i]!=0){
			while(v[i]<v[k] && vc[i]!=vc[k] && v[i]!=0){
				ans+=v[i];
				v[k]-=v[i];
				i++;
			}
		}
		if(vc[i]==vc[k]){
			while(vc[i]==vc[k]){
				if(v[i]>v[k]){
					k--;
				} else if(v[i]<v[k]){
					i++;
				} else{
					i++;
					k--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
