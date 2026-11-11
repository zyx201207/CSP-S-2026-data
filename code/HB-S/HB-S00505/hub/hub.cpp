#include<bits/stdc++.h>
using namespace std;
long long a[100000000],b[100000000];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long n,m,t,sum=0;
	cin >> n >> m;
	if(m==0){
		cout << 1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(i==(n+1)/2){
			t=a[i];
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){		
		if(t>=a[i]){
			b[i]=t-a[i];
		}else{
			b[i]=a[i]-t;
		}
	}	
	sort(b+1,b+1+n);	
	for(int i=1;i<=n;i++){
		if(m==0){
			cout << sum ;
			return 0;
		}
		m-=b[i];
		sum++;
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}








