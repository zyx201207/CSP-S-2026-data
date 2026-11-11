#include<bits/stdc++.h>
using namespace std;
long long ans;
struct node{
	int x;
	char c;
	
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long l,r;
	l=0;
	r=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		cin>>a[i].c;
		r+=a[i].x;
	}
	long long mid=r/2;
	int i=1;
	int j=n;
	if(r%2==1){
		while(r>=mid+2&&l<=mid){
			if (i!=j){
				int q=mid-l;
				int w=r-mid-1;
				if(q-a[i].x<w-a[j].x&&a[i].c!=a[j].c){
				
					l+=a[j].x;
					r-=a[j].x;
					a[i].x-=a[j].x;
					ans+=a[j].x;
						j--;
				}else if(w-a[j].x<q-a[i].x&&a[i].c!=a[j].c){
				
					l+=a[i].x;
					r-=a[i].x;
					a[j].x-=a[i].x;
					ans+=a[j].x;
					i++;
				}else if(w-a[j].x==q-a[i].x&&a[i].c!=a[j].c ){
					
					l+=a[i].x;
					r-=a[j].x;
					ans+=a[i].x;
					i++;
					j--;
				}else if(q-a[i].x<w-a[j].x&&a[i].c==a[j].c){
					
					l+=a[j].x;
					r-=a[j].x;
					a[i].x-=a[j].x;
					j--;
				}else if(w-a[j].x<q-a[i].x&&a[i].c==a[j].c){
					
					l+=a[i].x;
					r-=a[i].x;
					a[j].x-=a[i].x;
				i++;
				}else{
					
					l+=a[j].x;
					r-=a[j].x;
					i++;
					j--;
				}
			}else{
				break;
			}
		}
		cout<<ans<<endl;
	}else{
		while(r>=mid+1&&l<=mid){
			if (i!=j){
				int q=mid-l;
				int w=r-mid;
				if(q-a[i].x<w-a[j].x&&a[i].c!=a[j].c){
					l+=a[j].x;
					r-=a[j].x;
					
					
					a[i].x-=a[j].x;
					ans+=a[j].x;
					j--;
				}else if(w-a[j].x<q-a[i].x&&a[i].c!=a[j].c){
					l+=a[i].x;
					r-=a[i].x;
					
					
					a[j].x-=a[i].x;
					ans+=a[j].x;
					i++;
				}else if(w-a[j].x==q-a[i].x&&a[i].c!=a[j].c ){
					l+=a[i].x;
					r-=a[j].x;
					
					ans+=a[i].x; 
					i++;
					j--;
				}else if(q-a[i].x<w-a[j].x&&a[i].c==a[j].c){
					
					l+=a[j].x;
					r-=a[j].x;
					a[i].x-=a[j].x;
					j--;
				}else if(w-a[j].x<q-a[i].x&&a[i].c==a[j].c){
					
					l+=a[i].x;
					r-=a[i].x;
					a[j].x-=a[i].x;
					i++;
				
				}else{
					
					l+=a[j].x;
					r-=a[j].x;
					i++;
					j--;
				}
			}else{
				break;
			}
		}
		cout<<ans<<endl;		
	}
	return 0;
}
