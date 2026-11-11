#include<bits/stdc++.h>
using namespace std;
long long a[100013],b[100013],a1[50010],a2[50010];
long long ai,cnt=0,ans;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	queue<long long>q;
	int n;cin>>n;
	for(int i=0;i<n;i++){
		cin>>ai>>c;
		cnt+=ai;
		a[i]+=ai;
		b[i]+=c-96;
	}
	for(int i=0;i<cnt;i++){
		for(int j=0;j<a[i];j++){
			q.push(b[i]);
		}
	}
	for(int i=0;i<cnt/2;i++){
		a1[i]+=q.front();
		q.pop();
	}
	if(cnt%2==0){	
		for(int i=cnt/2-1;i>=0;i--){
			a2[i]+=q.front();
			q.pop();
		}
	}
	else{
		q.pop();
		for(int i=cnt/2-1;i>=0;i--){
			a2[i]+=q.front();
			q.pop();
		}
	}
	for(int i=0;i<cnt/2;i++){
		if(a1[i]!=a2[i]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
