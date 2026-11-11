#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[200100],k=1,h,s[200100];
	int q[200100]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;i++){k=1;
			h=1;
			while(q[k]!=0 && q[k]!=a[j]) k++;
			while(q[h]!=0) h++;
			if(q[k]==a[j]){
				for(int g=k;g<=h;g++)
				q[g]=0;
			q[k]=a[j];
		}
		k=1;
		while(q[k]!=i && q[k]!=0) k++;
		if(q[k]==i) s[i]++;
	}
	for(int i=1;i<=m;i++)
	cout<<s[i]<<" ";
}
}
