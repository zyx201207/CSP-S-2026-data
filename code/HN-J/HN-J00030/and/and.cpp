#include<cstdio>
#include<string>
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

void setio(string filename,string inSu=".in",string outSu=".out"){
	string in=filename+inSu;
	string out=filename+outSu;
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
}

#define max_def(num1,num2)\
((num1)>(num2)?(num1):(num2))

const int MAXN=2e5+10;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	setio("and");
	int num1,num2;
	int list[MAXN]={0};
	scanf("%d%d",&num1,&num2);
	int maxn=INT_MIN;
	for(int i=1;i<=num1;i++)
		scanf("%d",list+i);
	sort(list+1,list+num1+1);
	for(int i=num1;i>=1;i--){
		if(list[i]<maxn)
			break;
		int curr=list[i];
		for(int j=2;j<=num2;j++)
			curr&=list[i-j+1];
		maxn=max_def(maxn,curr);
	}
	printf("%d",maxn);
	return 0;
}
