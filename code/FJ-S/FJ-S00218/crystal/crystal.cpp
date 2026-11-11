#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],cnt;
int s(int x,int d){
	int ans=0;
	for(int i=x;i<=n;i++){
		if(b[i]==b[i+1]){
			d+=1;
		}else{
			int l;
			l=m/(b[i+1]-b[i]);
			m=m-(b[i+1]-b[i])*min(l,d);
			ans+=min(l,d);
			d=l+1;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+n);
	int c=a[2]-a[1];
	bool dc=true;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=c){
			dc=false;
		}
	}
	if(dc){
		if(c==0){
			cout<<n;
		}else{
			int s=1,l=1;
			while(m>l){
				l+=s;
				s++;
			}
			if(l==m){
				cout<<min(n,s);
			}else{
				cout<<min(m/c-1,n);
			}
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++){
		int d=1;
		for(int j=i+1;j<=n;j++){
			if(b[i]==b[j]){
				d++;
			}else{
				break;
			}
		}
		cnt=max(cnt,s(i,d) );
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
