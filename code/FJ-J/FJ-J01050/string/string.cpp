#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<climits>
using namespace std;
long long before[(int)2e8];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int A;
	cin>>A;
	int point=0;
	for(int i=1;i<=A;i++){
		int num;
		char c;
		cin>>num>>c;
		for(int i=1;i<=num;i++){
			before[point]=c;
			point++;
		}
	}
	int bsiz=point;
	int sum=0;
	for(int i=0;i<bsiz/2;i++){
		if(before[i]!=before[bsiz-1-i]){
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0; 
} 
