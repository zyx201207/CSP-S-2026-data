#include<bits/stdc++.h>
using namespace std;
long long a[10000005];
struct ks{
	char f;
	int v;
}bl[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>bl[i].v;
		cin>>bl[i].f;
		int k=(int)(bl[i].f-'a');
		for(int j=ans;j<ans+bl[i].v;j++){
			a[j]=k;
		}
		ans+=bl[i].v;
	}
	int mid;
	if(ans%2==0){
		mid=ans/2;
	}else{
		mid=ans/2+1;
	}
	long long h=0;
	for(int i=0;i<ans;i++){
		if(i!=mid){
			if(a[i]!=a[ans-i-1]){
				h++;
			}
		}else{
			break;
		}
	}
	cout<<h<<endl;
	return 0;
}
