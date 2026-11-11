#include<bits/stdc++.h>
using namespace std;
int main(){
    int l,num,word;
    cin>>l;
    int tmp=0;
    for(int i=0;i<=l;i++){
    cin>>num>>word;
    }
    int a[num]={word};
    for(int i=0;i<num%2;i++){
	if(a[0+i]==a[num-i]){
		tmp+0;
	else tmp+1;
		}
	}
	cout<<tmp;
	return 0;
}
