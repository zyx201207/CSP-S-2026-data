 #include<bits/stdc++.h>
 using namespace std;
 int a[100000005];
 int b[100000000];
 int main(){
 	freopen("std.in","r",stdin);
	freopen("std.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int w=n;
	for(int i=1;i<=w;i++){
		int flag=false;
		for(int j=1;j<i;j++){
			if(a[i]==a[j])flag=true;
		}
		if(flag==true){
			int h=1;
			for(int j=n+1;j<n+i-1;j++){
				a[j]=a[h];
				h++;
			}
			n+=i-1;
			for(int j=i+1;j<=n;j++){
				b[a[j]]++;
			}
		}else{
			for(int j=i+1;j<=n;j++){
				b[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
 	return 0;
 } 
