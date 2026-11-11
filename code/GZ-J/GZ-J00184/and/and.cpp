#incldue<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]<4){
			sum++;
		}
	}
    if(sum==n){
	sort(a+1,a+1+n,greater<int>());
		int g=0;
    	for(int i=1;i<=m;i++){
    		if(a[i]==2){
    			g=1;
			}
			if(a[i]=1&&g==1){
				cout<<0;
				return 0;
			}
			if(a[i]=0){
				cout<<0;
				return 0;
			}
		}
		cout<<a[m];
    	return 0;
    	
	}else{
		sort(a+1,a+1+n,greater<int>());
    	cout<<a[m];
    	return 0;
	}
	return 0;
}
