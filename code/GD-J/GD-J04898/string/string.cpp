#include<bits/stdc++.h>
using namespace std;
const int N=200008;
long long n,ans,t=0,x=0,y=0,t1=0;
struct edge{
	char b;
	int s;
}a[N];
int main(){
	freopen("string.in ","r",stdin);
	freopen("string.out ","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].b;
		t+=a[i].s; 
	}
	if(t%2==1){
		for(int i=1;i<=n;i++){
			t1+=a[i].s;
			if(t1>(t-1)/2) {a[i].s--;break;}
		}
		t=(t-1)/2;
	} 
    else t=t/2;
	while(1){
		int i=1,j=n;
		if(a[i].s<=t&&a[j].s<=t){
		    t-=min(a[i].s,a[j].s);
			if(a[i].b==a[j].b){		
				if(a[i].s>a[j].s) a[i].s-=a[j].s,j--;
				else if(a[i].s==a[j].s) j--,i++;
				else a[j].s-=a[i].s,i++;
			}  
			else {
				ans+=min(a[i].s,a[j].s);
				if(a[i].s>a[j].s) a[i].s-=a[j].s,j--;
				else if(a[i].s==a[j].s) j--,i++;
				else a[j].s-=a[i].s,i++;	
			}
		}
		else{
			if(a[i].s>t){
				a[i].s-=(a[i].s-t)*2;
				t--;
			}
			else {
				a[j].s-=(a[j].s-t)*2;
				t--;
			}
		}
		if(t==0) {cout<<ans;break;}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
