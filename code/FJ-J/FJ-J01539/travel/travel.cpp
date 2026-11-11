#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int b,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int b=0;
	int d=0;
	if(c1==c2){
		cout<<"1";
	}
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1=="01A" or s1=="01B" or s1=="01C" or s1=="01D" or s1=="01F"){
		if(s2=="01A" or s2=="01B" or s2=="01C" or s2=="01D" or s2=="01F")
			cout<<"1";
			b=1;
			if((s1=="01F" and s2=="01D") or (s1=="01D" and s2=="01F")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="01A" and s2=="01B") or (s1=="01B" and s2=="01C") or (s1=="01B" and s2=="01A") or (s1=="01C" and s2=="01B")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="01A" and s2=="01C") or s1=="01C" and s2=="01A"){
				cout<<"10";
				d=1;
				return 0;
			}
			if(d==0){
				cout<<"00";
			}
		}
	if(s1=="02A" or s1=="02B" or s1=="02C" or s1=="02D" or s1=="02F"){
		if(s2=="02A" or s2=="02B" or s2=="02C" or s2=="02D" or s2=="02F")
		    cout<<"1";
		    b=1;
		    if((s1=="02F" and s2=="02D") or (s1=="02D" and s2=="02F")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="02A" and s2=="01B") or (s1=="02B" and s2=="02C") or (s1=="02B" and s2=="02A") or (s1=="02C" and s2=="02B")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="02A" and s2=="02C") or s1=="02C" and s2=="02A"){
				cout<<"10";
				d=1;
				return 0;
			}
			if(d==0){
				cout<<"00";
			}
}
	if(s1=="03A" or s1=="03B" or s1=="03C" or s1=="03D" or s1=="03F"){
		if(s2=="03A" or s2=="03B" or s2=="03C" or s2=="03D" or s2=="03F")
		    cout<<"1";
		    b=1;
		    if((s1=="03F" and s2=="03D") or (s1=="03D" and s2=="03F")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="03A" and s2=="03B") or (s1=="03B" and s2=="03C") or (s1=="03B" and s2=="03A") or (s1=="03C" and s2=="03B")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="03A" and s2=="03C") or s1=="03C" and s2=="03A"){
				cout<<"10";
				d=1;
				return 0;
			}
			if(d==0){
				cout<<"00";
			}
	}
	if(s1=="04A" or s1=="04B" or s1=="04C" or s1=="04D" or s1=="04F"){
		if(s2=="04A" or s2=="04B" or s2=="04C" or s2=="04D" or s2=="04F")
		    cout<<"1";
		    b=1;
		    if((s1=="04F" and s2=="04D") or (s1=="04D" and s2=="04F")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="04A" and s2=="04B") or (s1=="04B" and s2=="04C") or (s1=="04B" and s2=="04A") or (s1=="04C" and s2=="04B")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="04A" and s2=="04C") or s1=="04C" and s2=="04A"){
				cout<<"10";
				d=1;
				return 0;
			}
			if(d==0){
				cout<<"00";
			}
	}
	if(s1=="05A" or s1=="05B" or s1=="05C" or s1=="05D" or s1=="05F"){
		if(s2=="05A" or s2=="05B" or s2=="05C" or s2=="05D" or s2=="05F")
		    cout<<"1";
		    b=1;
		    if((s1=="05F" and s2=="05D") or (s1=="05D" and s2=="05F")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="05A" and s2=="05B") or (s1=="05B" and s2=="05C") or (s1=="05B" and s2=="05A") or (s1=="05C" and s2=="05B")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="05A" and s2=="05C") or s1=="05C" and s2=="05A"){
				cout<<"10";
				d=1;
				return 0;
			}
			if(d==0){
				cout<<"00";
			}
	}
	if(s1=="06A" or s1=="06B" or s1=="06C" or s1=="06D" or s1=="06F"){
		if(s2=="06A" or s2=="06B" or s2=="06C" or s2=="06D" or s2=="06F")
		    cout<<"1";
		    b=1;
		    if((s1=="06F" and s2=="06D") or (s1=="06D" and s2=="06F")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="06A" and s2=="06B") or (s1=="06B" and s2=="06C") or (s1=="06B" and s2=="06A") or (s1=="06C" and s2=="06B")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="06A" and s2=="06C") or s1=="06C" and s2=="06A"){
				cout<<"10";
				d=1;
				return 0;
			}
			if(d==0){
				cout<<"00";
			}
	}
	if(s1=="07A" or s1=="07B" or s1=="07C" or s1=="07D" or s1=="07F"){
		if(s2=="07A" or s2=="07B" or s2=="07C" or s2=="07D" or s2=="07F")
		    cout<<"1";
		    b=1;
		    if((s1=="07F" and s2=="07D") or (s1=="07D" and s2=="07F")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="07A" and s2=="07B") or (s1=="07B" and s2=="07C") or (s1=="07B" and s2=="07A") or (s1=="07C" and s2=="07B")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="07A" and s2=="07C") or s1=="07C" and s2=="07A"){
				cout<<"10";
				d=1;
				return 0;
			}
			if(d==0){
				cout<<"00";
			}
	}
	if(s1=="08A" or s1=="08B" or s1=="08C" or s1=="08D" or s1=="08F"){
		if(s2=="08A" or s2=="08B" or s2=="08C" or s2=="08D" or s2=="08F")
		    cout<<"1";
		    b=1;
		    if((s1=="08F" and s2=="08D") or (s1=="08D" and s2=="08F")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="08A" and s2=="08B") or (s1=="08B" and s2=="08C") or (s1=="08B" and s2=="08A") or (s1=="07C" and s2=="08B")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="08A" and s2=="08C") or s1=="08C" and s2=="08A"){
				cout<<"10";
				d=1;
				return 0;
			}
			if(d==0){
				cout<<"00";
			}
	}
	if(s1=="09A" or s1=="09B" or s1=="09C" or s1=="09D" or s1=="09F"){
		if(s2=="09A" or s2=="09B" or s2=="09C" or s2=="09D" or s2=="09F")
		cout<<"1";
		b=1;
		if((s1=="09F" and s2=="09D") or (s1=="09D" and s2=="09F")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="09A" and s2=="09B") or (s1=="09B" and s2=="09C") or (s1=="09B" and s2=="09A") or (s1=="09C" and s2=="09B")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="09A" and s2=="09C") or s1=="09C" and s2=="09A"){
				cout<<"10";
				d=1;
				return 0;
			}
			if(d==0){
				cout<<"00";
			}
	}
	if(s1=="10A" or s1=="10B" or s1=="10C" or s1=="10D" or s1=="10F"){
		if(s2=="10A" or s2=="10B" or s2=="10C" or s2=="10D" or s2=="10F")
		cout<<"1";
		b=1;
		if((s1=="10F" and s2=="10D") or (s1=="10D" and s2=="10F")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="10A" and s2=="10B") or (s1=="10B" and s2=="10C") or (s1=="10B" and s2=="10A") or (s1=="10C" and s2=="10B")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="10A" and s2=="10C") or s1=="10C" and s2=="10A"){
				cout<<"10";
				d=1;
				return 0;
			}
			if(d==0){
				cout<<"00";
			}
	}
	if(s1=="11A" or s1=="11B" or s1=="11C" or s1=="11D" or s1=="11F"){
		if(s2=="11A" or s2=="11B" or s2=="11C" or s2=="11D" or s2=="11F")
		cout<<"1";
		b=1;
		if((s1=="11F" and s2=="11D") or (s1=="11D" and s2=="11F")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="11A" and s2=="11B") or (s1=="11B" and s2=="11C") or (s1=="11B" and s2=="11A") or (s1=="11C" and s2=="11B")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="11A" and s2=="11C") or s1=="11C" and s2=="11A"){
				cout<<"10";
				d=1;
				return 0;
			}
			if(d==0){
				cout<<"00";
			}
	}
	if(s1=="12A" or s1=="12B" or s1=="12C" or s1=="12D" or s1=="12F"){
		if(s2=="12A" or s2=="12B" or s2=="12C" or s2=="12D" or s2=="12F")
		cout<<"1";
		b=1;
		if((s1=="12F" and s2=="12D") or (s1=="12D" and s2=="12F")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="12A" and s2=="12B") or (s1=="12B" and s2=="12C") or (s1=="12B" and s2=="12A") or (s1=="12C" and s2=="12B")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="12A" and s2=="12C") or s1=="12C" and s2=="12A"){
				cout<<"10";
				d=1;
				return 0;
			}
			if(d==0){
				cout<<"00";
			}
	}
	if(s1=="13A" or s1=="13B" or s1=="13C" or s1=="13D" or s1=="13F"){
		if(s2=="13A" or s2=="13B" or s2=="13C" or s2=="13D" or s2=="13F")
		cout<<"1";
		b=1;
		if((s1=="13F" and s2=="13D") or (s1=="13D" and s2=="13F")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="13A" and s2=="13B") or (s1=="13B" and s2=="13C") or (s1=="13B" and s2=="13A") or (s1=="13C" and s2=="13B")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="13A" and s2=="13C") or s1=="13C" and s2=="13A"){
				cout<<"10";
				d=1;
				return 0;
			}
			if(d==0){
				cout<<"00";
			}
	}
	if(s1=="14A" or s1=="14B" or s1=="14C" or s1=="14D" or s1=="14F"){
		if(s2=="14A" or s2=="14B" or s2=="14C" or s2=="14D" or s2=="14F")
		cout<<"1";
		b=1;
		if((s1=="14F" and s2=="14D") or (s1=="14D" and s2=="14F")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="14A" and s2=="14B") or (s1=="14B" and s2=="14C") or (s1=="14B" and s2=="14A") or (s1=="14C" and s2=="14B")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="14A" and s2=="14C") or s1=="14C" and s2=="14A"){
				cout<<"10";
				d=1;
				return 0;
			}
			if(d==0){
				cout<<"00";
			}
	}
	if(s1=="15A" or s1=="15B" or s1=="15C" or s1=="15D" or s1=="15F"){
		if(s2=="15A" or s2=="15B" or s2=="15C" or s2=="15D" or s2=="15F")
		cout<<"1";
		b=1;
		if((s1=="15F" and s2=="15D") or (s1=="15D" and s2=="15F")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="15A" and s2=="15B") or (s1=="15B" and s2=="15C") or (s1=="15B" and s2=="15A") or (s1=="15C" and s2=="15B")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="15A" and s2=="15C") or s1=="15C" and s2=="15A"){
				cout<<"10";
				d=1;
				return 0;
			}
			if(d==0){
				cout<<"00";
			}
	}
	if(s1=="16A" or s1=="16B" or s1=="16C" or s1=="16D" or s1=="16F"){
		if(s2=="16A" or s2=="16B" or s2=="16C" or s2=="16D" or s2=="16F")
		cout<<"1";
		b=1;
		if((s1=="16F" and s2=="16D") or (s1=="16D" and s2=="16F")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="16A" and s2=="16B") or (s1=="16B" and s2=="16C") or (s1=="16B" and s2=="16A") or (s1=="16C" and s2=="16B")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="16A" and s2=="16C") or s1=="16C" and s2=="16A"){
				cout<<"10";
				d=1;
				return 0;
			}
			if(d==0){
				cout<<"00";
			}
	}
	if(s1=="17A" or s1=="17B" or s1=="17C" or s1=="17D" or s1=="17F"){
		if(s2=="17A" or s2=="17B" or s2=="17C" or s2=="17D" or s2=="17F")
		cout<<"1";
		b=1;
		if((s1=="17F" and s2=="17D") or (s1=="17D" and s2=="17F")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="17A" and s2=="17B") or (s1=="17B" and s2=="17C") or (s1=="17B" and s2=="17A") or (s1=="17C" and s2=="17B")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="17A" and s2=="17C") or s1=="17C" and s2=="17A"){
				cout<<"10";
				d=1;
				return 0;
			}
			if(d==0){
				cout<<"00";
			}
	}
	if(s1=="18A" or s1=="18B" or s1=="18C" or s1=="18D" or s1=="18F"){
		if(s2=="18A" or s2=="18B" or s2=="18C" or s2=="18D" or s2=="18F")
		cout<<"1";
		b=1;
		if((s1=="18F" and s2=="18D") or (s1=="18D" and s2=="18F")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="18A" and s2=="18B") or (s1=="18B" and s2=="18C") or (s1=="18B" and s2=="18A") or (s1=="18C" and s2=="18B")){
				cout<<"11";
				d=1;
				return 0;
			}
			if((s1=="18A" and s2=="18C") or s1=="18C" and s2=="18A"){
				cout<<"10";
				d=1;
				return 0;
			}
			if(d==0){
				cout<<"00";
			}
	}
	if(b==0){
		cout<<"000";
	}
	return 0;
}
