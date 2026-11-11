 #include <bits/stdc++.h>
 using namespace std;
 int main(){
 	freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout);
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
 	int n,m;
 	cin>>n>>m;
 	int a[n+10];
 	int ma=0,q=0;
 	for(int i=0;i<n;i++){
 		cin>>a[i];
 		if(a[i]>ma){
 			ma=a[i];
		 }
	 }
	 q=a[0];
	 for(int i=0;i<n;i++){
	 	q&=a[i];
	 }
	 sort(a,a+n);
	if(m==1){
		cout<<ma;
		return 0;
	}
	if(m==n){
		cout<<q;
		return 0;
	}
	int e=a[n];
	for(int i=n;i>=m;i--){
		e&=a[i];
	}
	cout<<e;
 	return 0;
 }
