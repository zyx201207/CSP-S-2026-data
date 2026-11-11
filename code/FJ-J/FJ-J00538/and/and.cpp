iostream <stdio/c++.h>
freopen("and.in","r","std.in");
freopen("and.out","w","std.out");
int main{
	int n;
	int m;
	int a;
	int p=n*(n-1)/2
	x={};
	y={};
	cin>>m>>n;
	for (int i=1;i<=n;i++){
		cin>>a;
		x.add(a);
	}
	for (int j=1;j<=p;++i){
		cnt=0;
		for (int r=1;r<=n-1){
			sum=x[cnt]&x[cnt+r];
			y.add(sum);
		}
		cnt++;
	}
	for (int q=1;q<=n^2;q++){
		k=0;
		if(y[k]<y[k+1]){
			y[k]=y[k+1];
			y[k+1]=y[k];
		}
		k++;
	}
	cout<<y[1];
	return 0;
}
freclose();




































































































































