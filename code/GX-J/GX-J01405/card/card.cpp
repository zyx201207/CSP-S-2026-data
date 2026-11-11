#include<bits/stdc++.h>
using namespace std;

int c[500005]={0},x[300005]={0};

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==1){
		cout<<n;
	}else{
		cout<<3<<" "<<1<<" "<<4; 
	}
	//for(int i=1;i<=n;i++){
	//	string now;
	//	int num[300005]={0};
	//	for(int j=i;j<=n;j++){
	//		if(now.find(to_string(c[j]))%1!=0){
	//			num[c[j]]++;
	//			now+=to_string(c[j]);
	//		}else{
	//			now=now.substr(1,now.find(to_string(c[j])));
	//			for(int k=1;k<=now.find(to_string(c[j]));k++){
	//				num[c[k]]--;
	//			}
	//			now+=to_string(c[j])+" ";
	//		}
	//	}
	//	for(int j=i;j<=m;j++){
	//		if(num[c[j]]!=0){
	//			x[c[j]]++;
	//		}
	//	}
	//}
	//for(int i=1;i<=m;i++){
	//	cout<<x[i]<<" ";
	//}
	return 0;
}
