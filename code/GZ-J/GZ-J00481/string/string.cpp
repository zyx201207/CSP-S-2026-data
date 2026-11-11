//GZ-J00481 遵义市第十九中学 刁奕杰
#include<bits/stdc++.h>
using namespace std;
char arr1[10000000],arr2[10000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[100004],b=0,d,e=0;
	char c[100004];
	int z=1;
	long long num=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=z;j>=z+a[i];j++){
		arr1[j]=c[i];
		}z=z+a[i]+1;
		if(a[i]%2==1) b++;
		num=num+a[i]/2+b/2;
	}
	if(b%2==1){
		d=2;
	}else{
		d=1;
	}
		int j=1;
		for(int i=2*num+d;i>=num+d;i--){
			arr2[j]=arr1[i];
			j++;
		}
		for(int i=1;i<=num;i++){
			if(arr1[i]!=arr2[i]) e++;
		}
		cout<<e;
	return 0;
}

