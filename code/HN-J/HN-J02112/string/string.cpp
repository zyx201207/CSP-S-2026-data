#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int num;
	int a=0;
	cin >> num;
	int number[num]={};
	string zimu[num]={};
	for(int s=0;s<num;s++){
		cin >> number[s] >> zimu[s];
		a+=number[s];
	}
	int i=0,j=0;	
	int time=0;
	while(i!=num-1-j){
		if(number[i]=number[num-1-j]){
			if(zimu[i]!=zimu[num-1-i]){
				time+=number[i];
			}
			i++;
			j++;
		}
		else{
			if(number[i]>number[num-1-j]){
				if(zimu[i]!=zimu[num-1-i]){
					time+=number[num-1-j];
				}
				number[i]-=number[num-1-i];
				j++;
			}	
			else{
				if(zimu[i]!=zimu[num-1-i]){
					time+=number[i];
				}
				number[num-1-i]-=number[i];
				i++;					
			}		
		}
	}
	cout << time;
	return 0;
} 
