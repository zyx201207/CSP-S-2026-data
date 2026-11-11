#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],ans[200005];
string s[200005];
long long sum,aa[200005];
queue<string>q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	aa[0]=1;
	for(int i=1;i<=30;i++){
		aa[i]=aa[i-1]*2;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]="0000000000000000000000000000000";
		int cnt=0;
		while(a[i]){
			cnt++;
			s[i][cnt]=a[i]%2+48;
			ans[cnt]+=a[i]%2;
			a[i]/=2;
		}
		q.push(s[i]);
	}
	for(int i=31;i>=1;i--){
		int pos=0,cc=0;
		while(cc<n){
			string t=q.front();
			q.pop();
			cc++;
			if(t[i]=='1'){
				pos++;
				
				q.push(t);
			}else if(pos<=m){
				q.push(t);
			}else{
				n--;
			}
			
		}
		if(pos>=m){
			sum+=aa[i-1];
			int cnt=0;
			while(cnt<n){
				string t=q.front();
				q.pop();
				cnt++;
				if(t[i]=='1'){
					q.push(t);
				}else{
					n--;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
