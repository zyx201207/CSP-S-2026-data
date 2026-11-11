//GZ-S00207 六盘水市第四实验中学 吴宇祥 
#include<bits/stdc++.h>
using namespace std;

vector<int>a;
int b;

int main(){
	freopen("subway1.ans","r",stdin);
	freopen("subway.out","w",stdout);
	
	for(int i=0;i<5005;i++){
		cin>>b;
		a.push_back(b);
	}
	for(int i=0;i<a.size();i++){
		cout<<a[i]<<endl;
		if(a[i]==a[i+1]){
			break;
		}
	}
}
