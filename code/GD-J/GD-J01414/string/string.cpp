#include <bits/stdc++.h>
using namespace std;
struct sss{
	char lx;
	long long sl;
}a[200005],b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	char lalx='A';
	long long lasl=0,t=0,tot=0;
	for(int i=1;i<=n;i++){
		char x;
		long long y;
		cin>>y>>x;
		tot+=y;
		if(lalx==x){
			lasl+=y; 
		}else{
			if(lalx!='A'){
				t++;
				a[t].lx=lalx;
				a[t].sl=lasl;
			}
			lalx=x;
			lasl=y;
			
		}
	}
	t++;
	a[t].lx=lalx;
	a[t].sl=lasl;
	//cout<<t;
	for(int i=1;i<=t;i++){
		b[t-i+1].lx =a[i].lx;
		b[t-i+1].sl =a[i].sl;
	}
	
	long long i=1,j=1,ans=0;
	while(i<=t && j<=t){
	//	cout<<a[i].sl<<" "<<b[j].sl<<"   ";
		if(a[i].lx==b[j].lx){
			ans+=min(a[i].sl,b[j].sl);
		}
		
		if(a[i].sl==b[j].sl){
			i++;
			j++;
		}else if(a[i].sl<b[j].sl){
			b[j].sl-=a[i].sl;
			i++;
		}else if(a[i].sl>b[j].sl){
			a[i].sl-=b[j].sl;
			j++;	
		}
	}
	//cout<<tot<<ans;	
	cout<<(tot-ans)/2; 
	return 0;
} 
