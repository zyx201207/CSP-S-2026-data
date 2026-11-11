#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int a[n],s[2]={0,0},p[2]={-1,-1};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=0;i<n;i++){
			p[0]=-1;
			p[1]=-1;
			for(int j=i;j<n;j++){
				if(p[0]==a[j]){
					p[1]=-1;
				}else if(p[0]==-1){
					p[0]=a[j];
				}else if(p[1]==-1){
					p[1]=a[j];
				}
				cout<<p[0]<<" "<<p[1]<<endl; 
			}
			if(p[0]==1 or p[1]==1){
				s[0]++;
			}
			if(p[0]==2 or p[1]==2){
				s[1]++;
			}
		}
		cout<<s[0]<<" "<<s[1];
	}else if(m==1){
		cout<<n;
	}else{
		for(int i=0;i<m;i++){
			cout<<n<<" ";
		}
	}
	return 0;
}
