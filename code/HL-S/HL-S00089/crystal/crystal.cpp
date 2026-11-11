#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],sub[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	} 
	sort(a+1,a+1+n);
	int note=0;
	for(int i=2;i<=100;i++){
		if(a[i+1]-a[i]!=a[i]-a[i-1]){
			note=0;
			break;
		}
		note=1;
	} 
	for(int i=1;i<=100;i++){
		if(a[i]!=i){
			note=0;
			break;
		}
		note=2;
	}
	if(note==2){
		long long cnt=1,i=1;
		while(m>=0){
			m-=i;
			i++;
			if(m<0){
				cout<<cnt;
				return 0;
			}
			cnt++;
		}
	}
	if(note==1){
		m/=(a[2]-a[1]);
		long long cnt=1,i=1;
		while(m>=0){
			m-=i;
			i++;
			if(m<0){
				cout<<cnt;
				return 0;
			}
			cnt++;
		}
	}
	long long mid=(1+n)>>1,cnt=0,tot=0;
	long long standard=a[mid];
	int pro=0;
	for(int i=1;i<=n;i++){
		sub[i]=abs(standard-a[i]);
	}
	long long l=mid-1,r=mid+1; 
	while(1){
		if(sub[l]<=sub[r]&&l>=1){ 
			if(r!=mid+1) tot+=sub[l]+sub[r-1];
			else tot+=sub[l]; 
			if(tot>m){
				tot-=sub[l];
				pro=1;
			}
			else{
				cnt++;
				l--; 
				if(l==0) pro=1;
			}
		}
		else{
			long long cur=r-l-1; 
			if(l==mid-1) cur=r-mid;
			tot+=cur*(sub[r]-sub[r-1]);
			if(tot>m){
				tot-=cur*(sub[r]-sub[r-1]);
				pro=2; 
			}
			else{
				r++;
				cnt++;
				if(r>n) pro=2;
			}
		}
		if(pro==1){
			long long cur=r-l-1;
			tot+=cur*(sub[r]-sub[r-1]);
			if(tot>m){
				break; 
			}
			else{
				r++;
				cnt++;
				if(r>n) break;
			}
		}
		else if(pro==2){
			tot+=sub[l]+sub[r-1];
			if(tot>m){
			    break;		
			}
			else{
				cnt++;
				l--; 
				if(l==0) break;
			}
		}
		else{
			continue;
		}
	}
	cout<<cnt+1;
    return 0;
}
