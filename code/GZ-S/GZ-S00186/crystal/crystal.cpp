//南白初级中学 GZ-S00186 杨朝涵 
#include<bits/stdc++.h>
using namespace std;
int n,highNum=0,lowNum=0,HighP=0,LowP=0,sum=0,Repsum=0,lowNumsMin=0;
long long m,max1=-1000000000001,min1=1000000000001;
int arr[50001]={};
int highNumArr[10000001];
int lowNumArr[10000001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	int a=0;
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}
	
	for(int i=0;i<n;++i){
		if(max1<arr[i]){
			max1=arr[i];
		}
	}
	for(int i=0;i<n;++i){
		if(min1>arr[i]){
			min1=arr[i];
		}
	}
	for(int i=0;i<n;++i){
		if(arr[i]==max1||arr[i]>=max1-m){
			highNum++;
			highNumArr[HighP]=i;
			HighP++;
		}
		else if(arr[i]==min1||arr[i]<=min1+m){
			lowNum++;
			lowNumArr[LowP]=i;
			LowP++;
		}
	}
	lowNumsMin=lowNumArr[lowNum-1];
	if(highNum>lowNum){
		for(int i=0;i<highNum;++i){
			if(highNumArr[i]>=0){
				Repsum=Repsum+(max1-highNumArr[i]);
			}
			else{
				Repsum=Repsum+(max1-abs(highNumArr[i]));
			}
		}
		if(Repsum<=m){
			cout<<highNum;
			return 0;
		}
		if(Repsum>m){
			cout<<highNum;
			return 0;
		}
	}
	sort(lowNumArr,lowNumArr+lowNum-1);
	if(highNum<lowNum){
		for(int i=0;i<lowNum;++i){
			if(i>=0){
				Repsum=Repsum+(lowNumsMin-lowNumArr[i]);
			}
			else{
				Repsum=Repsum+(lowNumsMin-abs(lowNumArr[i]));
			}
		}
		if(Repsum<=m){
			cout<<lowNum;
			return 0;
		}
		if(Repsum>m){
			cout<<lowNum;
			return 0;
		}
	}
	return 0;
}
