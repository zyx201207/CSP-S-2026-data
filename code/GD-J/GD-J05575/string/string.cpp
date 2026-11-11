#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int len;
	cin>>len;
	long long l=0;
	long long num[len+1];
	char letter[len+1];
	for(int i=0;i<len;i++){
		cin>>num[i];
		l+=num[i];
		cin>>letter[i];
	}
	long long different=0;
	long long index=0,antin=len-1;
	while(index<antin){
		if(letter[index]!=letter[antin]){
			if(num[index]<num[antin]){
				num[antin]-=num[index];
				different+=num[index];
				index++;
			}
			else{
				num[index]-=num[antin];
				different+=num[antin];
				antin--;
				
			}
//			cout<<different<<endl;
		}
	}
	cout<<different;
	return 0;
}
