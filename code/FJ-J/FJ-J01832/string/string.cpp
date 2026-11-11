#include<bits/stdc++.h>
using namespace std;

struct Node{
	int num;
	string str;
	
};

int Num_dif(Node x,Node y){
	return x.num<y.num?x.num:y.num;
}

int n;
string tmp;
bool flag;
int ans_l;
Node arr[200005];

int main(){
	freopen("r","string.in",stdin);
	cin>>n;
	cin>>arr[1].num>>arr[1].str;
	if(n==1){
		cout<<0;
		return 0;
	}
	tmp=arr[1].str;
	for(int i=2;i<=n;i++){
		cin>>arr[i].num>>arr[i].str;
		if(arr[i].str!=tmp){
			flag=true;
		}
	}
	if(n==2){
		cout<<Num_dif(arr[1],arr[2]);
	}
	if(!flag){
		cout<<0;
		return 0;
	}
	for(int i=n/2,j=1+(n+1)/2;j<=n;i--,j++){
		cout<<"ij "<<i<<' '<<j<<endl;
		if(arr[i].str!=arr[j].str||arr[i].num!=arr[j].num){
			ans_l+=Num_dif(arr[i],arr[j]);
			cout<<ans_l<<' '<<endl;
		}
	}
	cout<<endl;
	cout<<ans_l;
	freopen("w","string.out",stdout);
	return 0;
}
