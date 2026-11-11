#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//不一定有序
	//用while从i往前填充，填充一个就++
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int k=a[0];
	for(int i=0;i<n;i++){
		a[i]=a[i]-(k-1);
//		cout<<a[i]<<" ";
	}
//	cout<<endl;
	sort(a,a+n);
	int max=-999;
	for(int i=0;i<n;i++){
		int num=1;
		int l=m;
		while(l>0){
			if((i-num)<0){
				l=0;
			}
			l-=(a[i]-a[i-num]);
//			cout<<a[i-num-1]<<" "<<l<<endl;
			if(l>=0){
				num++;
//				cout<<" "<<a[i-num-1]<<endl;
			}
		}
		if(max<num){
			max=num;
		}
//		cout<<endl;
	}
	cout<<max;
}
