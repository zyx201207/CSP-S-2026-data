#include <iostream>
#include <string> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin£©
	freopen("travel.out,"w",stdout)
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	 if(a==c) {
	 	printf("1");
	 }
	 else{
	 	printf("0");
	 }
    if(b[1]==d[1]){
	 		if(b[2]==d[2]) printf("1");
		 }
		 else{
		 	printf("0");
		 }
	 if(b[3]=='A'){
	 	if(d[3]=='B')  printf("1 1");
	    if(d[3]=='C')  printf("1 0");
	 }
	 else{
	 	printf("0 0");
	 }
	 if(b[3]=='E'){
	 	if(d[3]=='F')  printf("1 1");
	 }
	 else{
	 		printf("0 0");
	 }
	 if(b[3]=='B'){
	 	if(d[3]=='A')  printf("1 1");
	    if(d[3]=='C')  printf("1 1");
	 }
	 else{
	 	printf("0 0");
	 }
	 if(b[3]=='C'){
	 	if(d[3]=='B')  printf("1 1");
	    if(d[3]=='A')  printf("1 0");
	 }
	 else{
	 	printf("0 0");
	 }
	 if(b[3]=='F'){
	 	if(d[3]=='E')  printf("1 1");
	 }
	 else{
	 		printf("0 0");}
	 if(b[3]==d[3])		printf("0 0");
	 	return 0;
 }
