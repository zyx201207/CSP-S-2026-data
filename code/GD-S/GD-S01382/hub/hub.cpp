#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll h,m;
	string s;
	void init(ll hh,ll mm,string str){
		h=hh;m=mm;s=str;
	} 
	void clear(){
		h=0;m=0;s="";
	}
};
struct node2{
	node nd[50];
	ll len;
	void clear(){
		for(int i=0;i<49;i++){
			nd[i].clear();
		}
		len=0;
	}
	void insert(ll hh,ll mm,string str){
		node tmp;
		tmp.init(hh,mm,str);
		nd[++len]=tmp;
	}
	void print(){
		for(int i=1;i<=len;i++){
			cout<<nd[i].h<<":";
			if(nd[i].m<10)cout<<0;
			cout<<nd[i].m<<" ";
			cout<<nd[i].s<<endl;
		}
	}
}Arr;
string F(ll n,ll arr[]){
	string ret;
	for(int i=0;i<n;i++)ret+=(char)(arr[i]);
	return ret;
}
void f(){
	Arr.clear();
	ll arr1[5]={83,84,65,82,84};
	ll arr2[5]={65,67,32,84,49};
	ll arr3[5]={84,82,89,84,50};
	ll arr4[5]={84,82,89,84,51};
	ll arr5[8]={84,51,32,52,48,112,116,115};
	ll arr6[8]={84,50,32,51,50,112,116,115};
	ll arr7[6]={49,55,50,112,116,115};
	string str1=F(5,arr1);
	string str2=F(5,arr2);
	string str3=F(5,arr3);
	string str4=F(5,arr4);
	string str5=F(8,arr5);
	string str6=F(8,arr6);
	string str7=F(6,arr7);
	Arr.insert(14,30,str1);
	Arr.insert(15,2,str2);
	Arr.insert(15,2,str3);
	Arr.insert(16,10,str4);
	Arr.insert(18,0,str5);
	Arr.insert(18,8,str6);
	Arr.print();
	cout<<str7<<endl;
	ll arr8[4]={82,80,43,43};
	string str8=F(4,arr8);
	cout<<str8<<endl;
}
int main(){
	if(031!=25)f();
	return 0;
}
