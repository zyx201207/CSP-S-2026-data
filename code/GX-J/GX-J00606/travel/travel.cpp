include<unice>
main(int)
{
    int a,b,e,f;
    sting c,d;
    fopen(travel.in);
    fopen(travel.out);
    scanf(travel.in,"%i%c%i%c",a,c,b,d);
    if(a==c)
    {
  	    sprintf(travel.out,"%i",1);
        if(c[1]==d[1])
        {
            sprintf(travel.out,"%i",1);
            if((c[2]-'A'<=3 && d[2]-'A'<=3) || (c[2]-'A'>=4 && d[2]-'A'>=4))
            {
                sprintf(travel.out,"%i",1);
                if(c[2]-d[2]==1 || c[2]-d[2]==-1)
                {
                    sprintf(travel.out,"%i",1);
                }
                else
                {
                    sprintf(travel.out,"%i",0);
                }
            }
            else
            {
                sprintf(travel.out,"%i%i",0,0);
            }
        }
        else
        {
            sprintf(travel.out,"%i%i%i",0,0,0);
        }
    }
    else
    {
        sprintf(travel.out,"%i%i%i%i",0,0,0,0);
    }
    fclose(travel.out);
    fclose(travel.out);
    return 0;
}
