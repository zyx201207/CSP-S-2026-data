#include<iostream>
using namespace std;

int n,m,top=0,a[500005],as[500005]={},link[500005]={},last[500005]={},light[500005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		link[i]=i+1;
		if(last[a[i]]) link[i]=last[a[i]];
		last[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int ptr=i;
		for(int j=1;j<=m;j++) light[j]=0;
		while(1<=ptr&&ptr<=n){
			//cout<<i<<" "<<ptr<<"\n";
			if(!light[a[ptr]]) as[a[ptr]]++,light[a[ptr]]=1;
			ptr=link[ptr];
		}
	}
	for(int i=1;i<=m;i++) cout<<as[i]<<" ";
	return 0;
}
