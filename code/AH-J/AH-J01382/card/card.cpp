#include<bits/stdc++.h>
using namespace std;
string a,b;
int sum[300000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=0;k<b.size();k++){
				if(b[k]==a[j]){
					b[k]='\0';
					break;
				}
			}
			b+=a[j];
		}
		for(int j=0;j<b.size();j++){
			sum[b[j]-'0']++;
		}
	}
	for(int i=0;i<m;i++){
		cout<<sum[i]<<" "; 
	} 
	return 0;
}
