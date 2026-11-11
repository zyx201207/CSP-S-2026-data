  #include <bits/stdc++.h>
 using namespace std;
 int n,ai[200005],bi[200010];
 char ac[200005],bc[200010];
 long long m,ajie[200005],bjie[200010],c,bu=1,zhong;
 int main ( ){
 	freopen ("string.in","r",stdin);
 	freopen ("string.out","w",stdout);
 	cin >>n;
 	for (int i=1;i<=n;i++){
 		cin >>ai[i]>>ac[i];
 		m+=ai[i];
 		ajie[i]=m;
	 }
	 if (m%2==0){
	 	bu=0;
	 }
	 c=m/2;
	 long long ans=c;
	 for (int i=1,t=0;i<=n;i++){
	 	if (ajie[i]<=c){
	 		t++;
	 	    bi[t]=ai[i];
	 	    bjie[t]=ajie[i];
	 	    bc[t]=ac[i];
		 }
		 else {
		 	t++;
		 	bi[t]=ai[i]-(ajie[i]-c);
		 	bjie[t]=c;
		 	bc[t]=ac[i];
		 	zhong=t;
		 	t++;
		 	bi[t]=ajie[i]-c;
		 	bjie[t]=ajie[i]-bu;
		 	bc[t]=ac[i];
		 }
	 }
	 for (int i=1,j=1;i<=zhong;){
	 	if (bc[i]==bc[n-j+1]){
	 		ans-=min(bi[i],bi[n-j+1]);
		 }
		 if (bi[i]>bi[n-j+1]){
		 	bi[i]-=bi[n-j+1];
		 	j++;
		 }
		 else if (bi[i]<bi[n-j+1]){
		 	bi[n-j+1]-=bi[i];
		 	i++;
		 }
		 else{
		 	i++;
			 j++; 
		 }
	 }
	 cout <<ans;
 }
