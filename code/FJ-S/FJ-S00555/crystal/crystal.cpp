#include<iostream>
#include<cmath>
using namespace std;
long long a[500000];
void quicksort(int left,int right){
	if(left>right)
		return;
	int x=left, y=right;
	while(x<y){
		while(a[y]>=a[left]){
			y--;
		}
		while(a[x]<=a[left]){
			x++;
		}
		swap(a[x],a[y]);
	}
	swap(a[left],a[x]);
	quicksort(left,x-1);
	quicksort(x+1,right);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr);
	long long n, m;
	cin>>n>>m;
	bool flag1=true, flag2=true;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i!=(a[i]-1))
			flag1=false;
		else if(i>1&&(a[i]-a[i-1]!=(a[i-1]-a[i-2])))
			flag2=false;
	}
	long long j=0;
	long long x=1;
	if(flag1==true){
		while(j<=m&&x<=n){
			j+=x;
			x++;
		}
	}
	else if(flag2==true){
		while(j<=m&&x<=n){
			j+=x*(a[1]-a[0]);
			x++;
		}
	}
	else{
		quicksort(0,n-1);
		while(j<=m&&x<=n){
			j+=x*(a[x]-a[x-1]);
			x++;
		}
	}
	cout<<x-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
