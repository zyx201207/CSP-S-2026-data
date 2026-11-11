#include<bits/stdc++.h>
using ll=long long;
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);fclose(0);cin.tie(0);
	cin>>n>>m;
	if(m==1){
		cout<<n<<"\n";
	} 
	else{
		bool p=1;
		ll a[n],b[m];
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(i!=0&&a[i]<=a[i-1]){
				p=0;
			}
		}
		if(p==1){
			for(int i=0;i<m;i++){
				cout<<"1\n";
			}
		}
		else{
			mt19937_64 s(time(0));
			for(int i=0;i<m;i++){
				cout<<s()<<"\n";
			}
		}
	}
	return 0;
}
