#include<bits/stdc++.h>
using namespace std;
long long cnt,n,m,a[500010],t;
bool cmp(long long a,long long b){
	if(abs(a-t)<abs(b-t)) return 1;
	else if(abs(a-t)>abs(b-t)) return 0;
	else return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	t=a[n/2+1];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(m==0){
			break;
		}if(a[i]<t){
			if(m>=t-a[i]){
				m-=t-a[i];
				cnt++;
			}else{
				break;
			}
		}if(a[i]==t){
			cnt++;
		}
	}
	cout<<cnt;