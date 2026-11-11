#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	string a,s,d,f;
	char z,x,c,v;
	cin>>a;
	cin>>z>>x>>s;
	cin>>d;
	cin>>c>>v>>f;
	if(a==d){
	    cout<<"1";}
	else{
	    cout<<"0000";
		return 0;}
	if(z==c){
		if(x==v){
		cout<<"1";}
	else{
	    cout<<"000";
		return 0;}}
	if(s=="A"&&f=="B"){
		cout<<"1";}
	else{
	    if(s=="B"&&f=="A"){
		    cout<<"1";}
	    else{
	        if(s=="C"&&f=="B"){
		        cout<<"1";}
			else{
	            if(s=="B"&&f=="C"){
		            cout<<"1";}
				else{
				    if(s=="D"&&f=="F"){
					    cout<<"1";}
					else{
					    if(s=="F"&&f=="D"){
						    cout<<"1";}
						else{
						    if(s=="C"&&f=="A"){
							    cout<<"1";}
							else{
							    if(s=="A"&&f=="C"){
								    cout<<"1";}
								else{
								    cout<<"00";
									return 0;}}}}}}}}
	if(s=="A"&&f=="B"){
		cout<<"1";}
	else{
	    if(s=="B"&&f=="A"){
		    cout<<"1";}
	    else{
	        if(s=="C"&&f=="B"){
		        cout<<"1";}
			else{
	            if(s=="B"&&f=="C"){
		            cout<<"1";}
				else{
				    if(s=="D"&&f=="F"){
					    cout<<"1";}
					else{
					    if(s=="F"&&f=="D"){
						    cout<<"1";}
						else{
							cout<<"0";
							return 0;}}}}}}	
    return 0;} 

