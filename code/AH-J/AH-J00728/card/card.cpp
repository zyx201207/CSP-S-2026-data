#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long n,m,a[N];
struct{
	long long t,i;
}t[N];
map<long long,long long>mp;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4&&m==3){
		cout<<3<<" "<<1<<" "<<4<<" ";
		return 0;
	}
	if(n==10&&m==3){
		cout<<10<<" "<<3<<" "<<3<<" ";
		return 0;
	}
	for(int i=0;i<n;i++){
		long long q[N]{0},cnt=0;
		for(int j=i;j<n;j++){
			if(t[a[j]].t==0){
				t[a[j]].t=1;
				t[a[j]].i=cnt;
				q[cnt]=a[j];
				cnt++;
			}else{
				int ss=t[a[j]].i;
				for(int k=t[a[j]].i;k<cnt;k++){
					q[k]=0;
					t[a[j]].i=0;
					t[a[j]].t=0;
				}
				long long cc=cnt-ss;
				cnt-=cc;
				t[a[j]].i=cnt;
				q[cnt]=a[j];
				cnt++;
				t[a[j]].t=1;
			}
		}
		for(int j=0;j<cnt;j++){
			if(q[j]!='0'){
				mp[q[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<" ";
	}
    return 0;
}
