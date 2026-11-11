#include <bits/stdc++.h> 
using namespace std;
char c1[5],s1[5],c2[5],s2[5];
bool f1=0,f2=0,f3=0,f4=0;
bool check(char a,char b){ //在不在同一侧 
	if(a=='A' && b=='A'){
		return true;
	}
	if(a=='A' && b=='B'){
		return true;
	}
	if(a=='A' && b=='C'){
		return true;
	}
	if(a=='B' && b=='A'){
		return true;
	}
	if(a=='B' && b=='B'){
		return true;
	}
	if(a=='B' && b=='C'){
		return true;
	}
	if(a=='C' && b=='A'){
		return true;
	}
	if(a=='C' && b=='B'){
		return true;
	}
	if(a=='C' && b=='C'){
		return true;
	}
	if(a=='D' && b=='D'){
		return true;
	}
	if(a=='D' && b=='F'){
		return true;
	}
	if(a=='F' && b=='D'){
		return true;
	}
	if(a=='F' && b=='F'){
		return true;
	}
	return false;
}
int main(){
	ifstream fin("travel.in");
	ofstream fout("travel.out");
	for(int i=0;i<2;i++){
		fin>>c1[i];
	}
	for(int i=0;i<3;i++){
		fin>>s1[i];
	}
	for(int i=0;i<2;i++){
		fin>>c2[i];
	}
	for(int i=0;i<3;i++){
		fin>>s2[i];
	}//输入
	for(int i=0;i<2;i++){
		if(c1[i] != c2[i]){
			f1=1;//不在同一车厢
		}	
	}
	for(int i=0;i<2;i++) {
		if(f1) break;
		if(s1[i] != s2[i]){
			f2=1;//不在同一排 
		}
	}
	if(!f2 && check(s1[2],s2[2])){
		f3=1;//在同一侧 
	}else{
		f3=0;
	}	
	if(f3 && abs( (s1[2]-'0') - (s2[2]-'0')) == 1 ){
		f4=1;
	}else{
		f4=0;
	}
	if(f1){
		fout<<"0000";
		return 0;
	}else{
		fout<<"1";
	}//判断在不在一个车厢 
	if(f2){
		fout<<"0";
	}else{
		fout<<"1";
	}//在不在同一排 
	if(f3){
		fout<<"1";
	}else{
		fout<<"0";
	}
	if(f4){
		fout<<"1";
	}else{
		fout<<"0";
	}
	return 0;
}
