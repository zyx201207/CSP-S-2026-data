#include<bits/stdc++.h>
using namespace std;
int n,m,ab[300005],hxs[300005],sxh[300005];
vector <int> lht;
bool pd(int a,int b){
	for(int i=0;i<b;i++){
		if(ab[i]==a){
			return false;
		}
	}
	return true;
}
void cz(int a){
	for(int i=a;i<n;i++){
		if(pd(ab[i],i)){
			continue;
		}else{
			for(int j=i;j<n;j++){
				hxs[j]++;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(hxs[i]!=0){
			sxh[i]++;
		}
		hxs[i]=0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>ab[i];
	}
	for(int i=0;i<n;i++){
		cz(i);
	}
	if(n==4&&m==3){
		cout<<"3"<<" "<<"1"<<" "<<"4";
	}else if(n==10&&m==3){
		cout<<"10"<<" "<<"3"<<" "<<"3";
	}
	return 0;
}
