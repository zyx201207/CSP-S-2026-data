#include<bits/stdc++.h>
using namespace std;
int n,m,a[5100],sum1[5100],v[5100][2],s,x,sum2[5100];
bool b[5100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int l=i,r=0;
		for(int j=i+1;j<n;j++){
			if(a[i]==a[j]){
				r=j;
				//cout<<l<<" "<<r<<endl;
				v[s][0]=l;
				v[s][1]=r;
				s++;
				b[i]=1;
				break;	
			}
		}
		for(int j=l;j<r;j++) sum1[j]++;
	}
	for(int i=0;i<n;i++){
		if(b[i-1]&&i!=0){
			for(int j=v[x][0];j<v[x][1];j++){
				sum1[j]--;
			}
			x++;
		}
		for(int j=i;j<n;j++){
			if(sum1[j]==0){
				sum2[a[j]]++;
			}
		}
//		for(int j=0;j<n;j++){
//			cout<<sum1[j]<<" "; 
//		}
//		for(int j=1;j<=m;j++){
//			cout<<sum2[j]<<" ";
//		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<sum2[i]<<" ";
	}
	// luogu:jusen guanzhu pls,100+92+40+24=256,i am die;
}
