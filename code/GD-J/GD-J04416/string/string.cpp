#include<fstream>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string in;
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		unsigned int num;
		cin>>num;
		char nu;
		cin>>nu;
		for(int j = 0;j<num;j++){
			in+=nu;
		}
	}
	string rein;
	int count = 0,c = 0;
	while(1){
		c++;
		rein = "";
		for(int i = 0;i<in.size();i++){
			rein = in[i]+rein;
		}
		if(rein==in)break;
		for(int i = 0;i<in.size()/2+1;i++){
			if(rein[i]!=in[i]){
				rein[i] = in[i];
				count++;
			}
		}
		break;
	}
	cout<<count;
	return 0;
}
