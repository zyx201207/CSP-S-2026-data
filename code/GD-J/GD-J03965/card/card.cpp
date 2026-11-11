#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],temple[600000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	int alter=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		temple[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1+(i-1);j<=n;j++){
			int flag=1;
			for(int k=1;k<=alter;k++){
				if(temple[k]==a[j]) flag=0;
			}
			if(flag) temple[++alter]=a[j];
		} 
	}
	cout<<n<<" "<<n<<" "<<n;
	return 0;
}
