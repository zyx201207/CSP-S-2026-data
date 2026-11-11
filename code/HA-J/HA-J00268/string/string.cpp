 #include <bits/stdc++.h>
 using namespace std;
 int main(){
 	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
 	int n;
 	cin>>n;
 	int a[n+10];
 	char c[n+10];
 	int q=0,w=0,e=0;
 	for(int i=0;i<n;i++){
 		cin>>a[i]>>c[i];
 		if(c[i]==c[i-1]){
 			q=1;
		 }
		 if(a[i]%2!=0){
		 	w++;
		 }
		 if(a[i]==1){
		 	e++;
		 }
	}
		if(q==1){
		cout<<"0";
		return 0;
	}
	if(e==n){
		cout<<n-1;
		return 0;
	}
	if(w==1){
		cout<<"2";
		return 0;
	}

	if(n<=1){
		cout<<'0';
		return 0;
	}
	
 	return 0;
 }
