//GZ-J00258 Ñî³¯º­ 
#include <bits/stdc++.h>
using namespace std;
long long n,changeNum=0,maxChar=0;
long long numChar=0,FirstCharNum=0,maxCharNum=0;
string S,SwapS;
char cinChar,FirstChar;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	
	for(int i=0;i<n;++i){
		cin>>numChar>>cinChar;
		if(i==0){
			FirstChar = cinChar;
			FirstCharNum = numChar;
		}
		if(maxCharNum<numChar){
			maxCharNum=numChar;
			maxChar=cinChar;
		}
		for(int j=0;j<numChar;++j){
			S=S+cinChar;
		}
	}
	
	for(int i=S.length()-1;i>=0;--i){
		SwapS=SwapS+S[i];
	}
	
	if(SwapS==S){
		cout<<0;
		return 0;
	}
	//cout<<FirstCharNum<<" "<<FirstChar<<" "<<numChar<<" "<<cinChar;
	if(n%2!=0){
		if(numChar==FirstCharNum&&cinChar!=FirstChar){
			cout<<numChar;
			return 0;
		}
		if(numChar!=FirstCharNum&&cinChar==FirstChar){
			cout<< max(numChar,FirstCharNum)- min(numChar,FirstCharNum);
			return 0;
		}
		else{
			cout<< max(numChar,FirstCharNum);
			return 0;
		}	
	}
	else{
		if(FirstCharNum<=maxCharNum&&numChar<=maxCharNum){
			cout<<FirstCharNum+numChar;
		}
	}
	return 0;
}

